/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {  // this is time limited func 
       let fnpromise =  fn(...args)     // Aur question mein diya hai ki fn already async function hai, matlab:
 // khud hi ek Promise return karega.
       let timerpromise = new Promise((_ , reject)=>{
        setTimeout(()=> reject("Time Limit Exceeded") ,t )
       })

       return Promise.race([fnpromise , timerpromise])
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */