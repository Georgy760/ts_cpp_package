declare module '*.node' {
  const addon: (callback: (message: string) => void) => void;
  export = addon;
}
