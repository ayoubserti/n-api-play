const napi = require("../")

napi.hello();

console.log(napi.sum(5,1))

try{
    napi.sum(5)
}
catch(e)
{
    console.log(`catch it "${e}"`); 
}
