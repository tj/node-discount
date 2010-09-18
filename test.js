var assert = require('assert'),
    fs = require('fs'),
    markdown = require('./build/default/markdown');

assert.ok(markdown.version.match(/^\d+\.\d+\.\d+$/), 'version is improperly formatted');

for (var i = 0; i < 10; i++) {
  assert.equal(fs.readFileSync('test/test.html').toString(), markdown.parse(fs.readFileSync('test/test.md').toString()));
}

