
// 
// markdown.cc
// 
// (c) 2009 TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)
//

#include <v8.h>
#include <node.h>
#include <stdio.h>

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
  int flags;
  if (args.Length() < 1 || !args[0]->IsString())
    return ThrowException(Exception::TypeError(String::New("String expected")));
  
  if (args.Length() == 2){
    if (!args[1]->IsNumber()){
      return ThrowException(Exception::TypeError(String::New("Flag should be a number")));
    }else{
      flags = args[1]->Int32Value();
    } 
  } else {
    flags = 0;
  }

  MMIOT *doc;
  String::Utf8Value in(args[0]);
  if ((doc = mkd_string(*in, in.length(), flags)) == 0)
    return ThrowException(Exception::Error(String::New("Failed to parse markdown")));
  if (mkd_compile(doc, flags))
    len = mkd_document(doc, &buf);
  Handle<String> md = String::New(buf);
  mkd_cleanup(doc);
  return scope.Close(md);
}

/*
 * Initialize.
 */

extern "C" void
init (Handle<Object> target) {
  HandleScope scope;
  Handle<Object> flags;
  flags = Object::New();
  flags->Set(String::New("noLinks"), Number::New(MKD_NOLINKS));
  flags->Set(String::New("noImage"), Number::New(MKD_NOIMAGE));
  flags->Set(String::New("noPants"), Number::New(MKD_NOPANTS));
  flags->Set(String::New("noHTML"),  Number::New(MKD_NOHTML));
  flags->Set(String::New("strict"),  Number::New(MKD_STRICT));
  flags->Set(String::New("tagText"), Number::New(MKD_TAGTEXT));
  flags->Set(String::New("noExt"),   Number::New(MKD_NO_EXT));
  flags->Set(String::New("cdata"),   Number::New(MKD_CDATA));
  flags->Set(String::New("noSuperscript"), Number::New(MKD_NOSUPERSCRIPT));
  flags->Set(String::New("noRelaxed"), Number::New(MKD_NORELAXED));
  flags->Set(String::New("noTables"), Number::New(MKD_NOTABLES));
  flags->Set(String::New("noStrikethrough"), Number::New(MKD_NOSTRIKETHROUGH));
  flags->Set(String::New("toc"), Number::New(MKD_TOC));
  flags->Set(String::New("md1Compat"), Number::New(MKD_1_COMPAT));
  flags->Set(String::New("autolink"), Number::New(MKD_AUTOLINK));
  flags->Set(String::New("safelink"), Number::New(MKD_SAFELINK));
  flags->Set(String::New("noHeader"), Number::New(MKD_NOHEADER));
  flags->Set(String::New("tabStop"), Number::New(MKD_TABSTOP));
  flags->Set(String::New("noDivQuote"), Number::New(MKD_NODIVQUOTE));
  flags->Set(String::New("noAlphaList"), Number::New(MKD_NOALPHALIST));
  flags->Set(String::New("noDlist"), Number::New(MKD_NODLIST));
  flags->Set(String::New("extraFootnote"), Number::New(MKD_EXTRA_FOOTNOTE));
  target->Set(String::New("version"), String::New("0.2.0"));
  target->Set(String::New("flags"), flags);
  NODE_SET_METHOD(target, "parse", Parse);
}