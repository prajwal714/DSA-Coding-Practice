
let url=new URL("/charge?network=visa&amount=100&merchant_id=m001&charge_id=c001", "https://stripe.com");

console.log(url);
console.log(url.hostname);
console.log(url.pathname);