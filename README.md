# Install project dependencies
npm install

# Clean old build artifacts
cmake-js clean

# Configure the build
cmake-js configure

# Build the C++ addon
cmake-js build

# Compile TypeScript files
npm run build

# Run the Node.js application
npm start