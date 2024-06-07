/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function(s) {
    let result = "";
        let opened = 0;
        
        for (const char of s) {
            if (char === '(') {
                opened++;
                if (opened > 1) {
                    result += char;
                }
            } else {
                opened--;
                if (opened > 0) {
                    result += char;
                }
            }
        }
        
        return result;
};