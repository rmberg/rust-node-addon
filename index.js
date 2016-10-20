const addon = require('./node-addon/build/Release/addon');
console.log(addon.hello());
console.log(addon.fibonacci(25));
