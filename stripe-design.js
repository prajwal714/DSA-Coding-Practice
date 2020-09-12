
let networks=new Map();
let charges=new Map();
let merchants=new Map();


let charge=(url)=>
{
    let charge_id=url.searchParams.get("charge_id");
    let merchant_id=url.searchParams.get("merchant_id");
    let amount=url.searchParams.get("amount");
    let network=url.searchParams.get("network");

    let newCharge={
        "id": charge_id,
        "merchant_id": merchant_id,
        "amount": amount,
        "network": network
    }

    // console.log(merchants.has(merchant_id));
    if(!merchants.has(merchant_id))
    {
        merchants.set(merchant_id,{"merchant_id": merchant_id, "payout": 0});
        console.log(merchants.get(merchant_id));

    }

    charges.set(charge_id,newCharge);
    console.log(charges.get(charge_id));
    

}

let payout=(url)=>
{
    // console.log(url);
    let merchant_id=url.searchParams.get("merchant_id");
    console.log("Payout to: ", merchant_id);
    console.log(merchants.has(merchant_id));
    if(merchants.has(merchant_id))
    {
        let payout_balance=Math.ceil(merchants.get(merchant_id).payout);
        merchants.get(merchant_id).payout=0;
        console.log(merchant_id,",",payout_balance);
    }
}

let confirm=(url)=>
{
    let charge_id=url.searchParams.get("charge_id");
    console.log("ChargeID: ", charge_id);
    console.log(charges.has(charge_id));
    if(charges.has(charge_id))
    {
        let charge_details=charges.get(charge_id);
        let {amount, merchant_id, network}=charge_details;
       
        let percent=networks.get(network).percent;
        amount=parseFloat(amount);
        let payout_balance=amount-((2+percent)*0.01*amount);
        console.log("payout_balance: ",payout_balance);
        merchants.get(merchant_id).payout+=payout_balance;

        charges.delete(charge_id);

    }
}

let refund=(url)=>
{
    let charge_id=url.searchParams.get("charge_id");
    console.log("ChargeID: ", charge_id);
    // if(charges.has(charge_id))
    // {
        let charge_details=charges.get(charge_id);
        let {amount, merchant_id, network}=charge_details;
        amount=parseFloat(amount);
        let percent=networks.get(network).percent;

        let payout_balance=percent* 0.01*amount;
        console.log("To be deducted: ",payout_balance);
        merchants.get(merchant_id).payout-=payout_balance;
        charges.delete(charge_id);
    // }
}



function process_actions(actions)
{
    let m,n;
    n=Number(actions[0]);
    m=Number(actions[n+1]);
    console.log("inside actions");
    let i=1
    for(;i<=n;i++)
    {
        let card_details=actions[i].split(" ");
        console.log(card_details);
        networks.set(card_details[0],{"card_network": card_details[0], "percent": parseFloat(card_details[1])});
        console.log(networks.get(card_details[0]));
    }

    console.log(networks);
    i++;
    for(;i<actions.length; i++)
    {
        let url=new URL(actions[i], "https://stripe.com");
        let action=url.pathname;
        console.log("action: ",action);
        switch(action) {
            case "/charge":
                {
                    charge(url);
                }
                break;

            case "/payout" :
                {
                    payout(url);
                }
                break;

            case "/confirm" :
                {
                    confirm(url);
                }
                break;

            case "/refund" :
                {
                    refund(url);
                }
                break;
            default :
                console.log("Error action not found");
        }
    }
}

let actions=[
    "2",
"visa 2.0",
"mastercard 3.0",
"8",
"/charge?network=visa&amount=1000&merchant_id=m001&charge_id=c001",
"/charge?merchant_id=m001&amount=1000&network=mastercard&charge_id=c002",
"/confirm?charge_id=c001",
"/confirm?charge_id=c002",
"/payout?merchant_id=m001",
"/charge?network=visa&amount=1000&merchant_id=m001&charge_id=c003",
"/confirm?charge_id=c003",
"/payout?merchant_id=m001"

]

process_actions(actions);