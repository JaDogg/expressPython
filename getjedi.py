def get_completions(source, row, col):
    try:
        import jedi
        import json
        jedi.Script(source, row, col, '')
        return json.dumps([x.name for x in script.completions()])
    except:
        return "[]"
