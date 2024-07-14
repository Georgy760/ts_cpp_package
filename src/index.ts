// src/index.ts
import * as path from 'path';
import { tsHello, tsGreet } from './typescriptFunctions';


// Dynamically resolve the path to the hello.node module
const helloPath = path.resolve(__dirname, '../build/Release/hello.node');
const cppWrapperPath = path.resolve(__dirname, '../build/Release/cppWrapper.node');
const hello = require(helloPath);
const cppWrapper = require(cppWrapperPath);

// Call TypeScript functions
console.log(tsHello());
console.log(tsGreet('World'));

// Call C++ functions
console.log(hello.hello());
console.log(hello.greet('World'));

// Call TypeScript functions from C++
cppWrapper.callTsHello();
cppWrapper.callTsGreet('World');
