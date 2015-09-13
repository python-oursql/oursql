from docutils import nodes

def mysqlfunc_role(name, rawtext, text, lineno, inliner, 
        options=None, content=None):
    """Show references to mysql documentation."""
    options = options or {}
    ref = u'http://dev.mysql.com/doc/refman/5.0/en/%s.html' % (
        text.replace('_', '-'))
    lnode = nodes.literal(rawtext, text + '()', **options)
    node = nodes.reference(refuri=ref)
    node.append(lnode)
    return [node], []

def setup(app):
    app.add_role('mysqlfunc', mysqlfunc_role)
