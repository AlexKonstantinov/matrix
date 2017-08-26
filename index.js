/**
 * Created by papa on 26.08.2017.
 */

const p = require(`./build/release/addon`);
console.log(`start: ${new Date()}`);
console.log(p.hello());
console.log(`end: ${new Date()}`);

console.log(`start: ${new Date()}`);
let a = 3.145678, b = 2.178;
for (let i = 1; i<1000000000; i++) {
    a+=b;
}
console.log(a);
console.log(`end: ${new Date()}`);