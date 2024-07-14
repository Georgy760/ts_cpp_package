import * as path from 'path';

const addonPath = path.join(__dirname, '../build/Release/addon');
const addon = require(addonPath);

function callback(message: string): void {
  console.log(message);
}

addon(callback);
