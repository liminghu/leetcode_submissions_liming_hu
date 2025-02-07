// https://leetcode.com/problems/create-hello-world-function

/**
 * @return {Function}
 */
var createHelloWorld = function() { //Write a function createHelloWorld. It should return a new function that always returns "Hello World".
    
    return function(...args) {
        return  "Hello World";        
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */