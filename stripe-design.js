
let networks=new Map();
let charges=new Map();
let merchants=new Map();

function Merchant(id) {
    this.id=id;
    this.payout=0;
}

function Network(card_network, percent)
{
    this.card_network=card_network;
    this.percent=percent;
}

function Charge(id, amount, merchant_id, network_name){
    this.id=id;
    this.merchant_id=merchant_id;
    this.amount=amount;
    this.network_name=network_name;
}


