#include <node.h>
#include <stdint.h>
#include <stdio.h>

extern "C" int32_t fibonacci(int32_t value);

namespace addon {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Integer;
using v8::Value;

void SayHello(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void Fibonacci(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int32_t value = args[0]->IntegerValue();
  args.GetReturnValue().Set(Integer::New(isolate, fibonacci(value)));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", SayHello);
  NODE_SET_METHOD(exports, "fibonacci", Fibonacci);
}

NODE_MODULE(addon, init)

}  // namespace addon
