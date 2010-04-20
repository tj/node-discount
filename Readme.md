
# Markdown.js

  node bindings for the C "discount" markdown implementation by David Parsons.
  Currently only simply parsing is supported, flags hopefully coming soon.
  
## Installation

You will need to install [Discount](http://github.com/Orc/discount) from source, or using
a package management tool such as [homebrew](http://github.com/mxcl/homebrew), or apt-get.

When using the [Kiwi](http://github.com/visionmedia/kiwi) package manager for node run:

    $ kiwi install markdown

Otherwise you will need to update the git submodules and run:

    $ make

In order to generate _build/markdown.node_.
  
## Usage

    var md = require('markdown')
    md.parse('markdown is *awesome*')
    // => "<p>markdown is <em>awesome</em></p>"

## License 

(The MIT License)

Copyright (c) 2009 TJ Holowaychuk &lt;tj@vision-media.ca&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.