
// 
// markdown.cc
// 
// (c) 2009 TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)
//

#include <v8.h>
#include <node.h>

extern "C" {
  #include <mkdio.h>
}

using namespace v8;
using namespace node;

/*
 * Parse the given string of markdown.
 */

static Handle<Value>
Parse(const Arguments& args) {
  HandleScope scope;
  char *buf;
  int len;
  if (args.Length() < 1 || !args[0]->IsString())
    return ThrowException(Exception::TypeError(String::New("String expected")));
  MMIOT *doc;
  String::Utf8Value in(args[0]);
  if ((doc = mkd_string(*in, in.length(), 0)) == 0)
    return ThrowException(Exception::Error(String::New("Failed to parse markdown")));
  if (mkd_compile(doc, 0))
    len = mkd_document(doc, &buf);
  Handle<String> md = String::New(buf);
  mkd_cleanup(doc);
  return scope.Close(md);
}

/*
 * Initialize.
 */

extern "C" void
init (Handle<Object> target)
{
  HandleScope scope;
  target->Set(String::New("version"), String::New("0.1.1"));
  NODE_SET_METHOD(target, "parse", Parse);
}