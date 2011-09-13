srcdir = '.'
blddir = 'build'
VERSION = '0.0.1'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')
  conf.check_cfg(atleast_pkgconfig_version='0.0.0', mandatory=True, errmsg='pkg-config was not found')

def build(bld):
  bld.exec_command('cp -r ../discount/* .')
  bld.exec_command('./configure.sh --with-dl=Both --enable-all-features && make')

  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.linkflags = ["-lmarkdown", "-mimpure-text", "-L."]
  obj.target = 'markdown'
  obj.source = 'src/markdown.cc'
  obj.cxxflags = ["-fPIC", "-I."]
