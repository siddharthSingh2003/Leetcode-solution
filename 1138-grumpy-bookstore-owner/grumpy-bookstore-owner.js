/**
 * @param {number[]} customers
 * @param {number[]} grumpy
 * @param {number} minutes
 * @return {number}
 */
var maxSatisfied = function(customers, grumpy, minutes) {
    let initialSatisfaction = 0;
    let maxExtraSatisfaction = 0;
    let currentWindowSatisfaction = 0;
    
    for (let i = 0; i < customers.length; i++) {
        if (grumpy[i] === 0) {
            initialSatisfaction += customers[i];
        } else if (i < minutes) {
            currentWindowSatisfaction += customers[i];
        }
    }
    
    maxExtraSatisfaction = currentWindowSatisfaction;
    
    for (let i = minutes; i < customers.length; i++) {
        currentWindowSatisfaction += customers[i] * grumpy[i];
        currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
        maxExtraSatisfaction = Math.max(maxExtraSatisfaction, currentWindowSatisfaction);
    }
    
    return initialSatisfaction + maxExtraSatisfaction;
};