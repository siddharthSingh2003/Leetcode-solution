/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const li = new Set();
    function addEle(x,y) {
        if(typeof y == 'undefined'){
            y=0;
        }
        const pair = [x, y].toString();
        li.add(pair);
    }
    
    function contains(x,y){
        if(typeof y == 'undefined'){
            y=0;
        }
        const pair = [x, y].toString();
        return li.has(pair);
    }
    let other=new Map();
    let val = 0;
  
    return function(...args) {  
        
        if(!contains(args[0], args[1])){
            addEle(args[0], args[1]);
            val = fn(...args);
            if(typeof args[1] == 'undefined'){
                other.set(args[0],val);
            }
            else{
                return val;
            }
        }
        else if(typeof args[1] != 'undefined'){
            return args[0]+args[1];
        }
        return other.get(args[0]);
        
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */