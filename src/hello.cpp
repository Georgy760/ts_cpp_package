// src/hello.cpp
#include <napi.h>
#include <string>

Napi::String Hello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello from C++!");
}

Napi::String Greet(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::string name = info[0].As<Napi::String>();
    return Napi::String::New(env, "Hello from C++ to " + name);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
    exports.Set(Napi::String::New(env, "greet"), Napi::Function::New(env, Greet));
    return exports;
}

NODE_API_MODULE(hello, Init)
