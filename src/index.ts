import * as path from 'path';

// Dynamically resolve the path to the hello.node module
const helloPath = path.resolve(__dirname, '../build/Release/hello.node');
const hello = require(helloPath);

console.log(hello.hello());
