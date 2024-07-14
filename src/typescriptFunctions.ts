// src/typescriptFunctions.ts
export function tsHello(): string {
  return "Hello from TypeScript!";
}

export function tsGreet(name: string): string {
  return `Hello, ${name} from TypeScript!`;
}

// Expose TypeScript functions globally for C++ to call
(global as any).tsHello = tsHello;
(global as any).tsGreet = tsGreet;
