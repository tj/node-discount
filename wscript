srcdir = '.'
blddir = 'build'
VERSION = '0.0.1'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')
  conf.check(
    lib = 'markdown',
    libpath = ['/usr/lib', '/usr/local/lib', '/opt/local/lib'],
    uselib_store = 'DISCOUNT'
  )

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.linkflags = ["-lmarkdown", "-mimpure-text"]
  obj.target = 'markdown'
  obj.source = 'src/markdown.cc'
  obj.uselib = 'DISCOUNT'
  obj.cxxflags = ["-fPIC"]
