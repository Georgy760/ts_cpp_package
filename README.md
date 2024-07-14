npm run build
npm start

nano src/addon.d.ts
npm run build

nano src/index.ts
nano tsconfig.json
npm install --save-dev typescript @types/node

npx node-gyp build
npx node-gyp configure
nano src/addon.cpp
nano binding.gyp
npm install node-addon-api

npm init -y
