declare module 'hello' {
  export function hello(): string;
  export function greet(name: string): string;
}

declare module 'cppWrapper' {
  export function callTsHello(): void;
  export function callTsGreet(name: string): void;
}
