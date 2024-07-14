// src/cpp_wrapper.cpp
#include <napi.h>
#include <iostream>

// Function to call TypeScript functions
void CallTsHello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    auto global = env.Global();
    
    if (global.Has("tsHello")) {
        auto tsHello = global.Get("tsHello").As<Napi::Function>();
        Napi::String result = tsHello.Call(global, {}).As<Napi::String>();
        // Output result to console
        std::cout << result.Utf8Value() << std::endl;
    } else {
        std::cerr << "TypeScript function tsHello not found!" << std::endl;
    }
}

void CallTsGreet(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    auto global = env.Global();
    
    if (global.Has("tsGreet")) {
        auto tsGreet = global.Get("tsGreet").As<Napi::Function>();
        Napi::String name = info[0].As<Napi::String>();
        Napi::String result = tsGreet.Call(global, { name }).As<Napi::String>();
        // Output result to console
        std::cout << result.Utf8Value() << std::endl;
    } else {
        std::cerr << "TypeScript function tsGreet not found!" << std::endl;
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "callTsHello"), Napi::Function::New(env, CallTsHello));
    exports.Set(Napi::String::New(env, "callTsGreet"), Napi::Function::New(env, CallTsGreet));
    return exports;
}

NODE_API_MODULE(cppWrapper, Init)
