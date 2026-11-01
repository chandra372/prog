def unify(x,y,subs={}):
    if subs is None:
        return None
    elif x==y:
        return subs
    elif isinstance(x,str) and x.islower():
        return unify_var(x,y,subs)
    elif isinstance(y,str) and y.islower():
        return unify_var(y,x,subs)
    elif isinstance(x,tuple) and isinstance(y,tuple)and len(x)==len(y):
        for a,b,in zip(x,y):
            subs=unify(a,b,subs)
            if subs is None:
                return None
        return subs
    else:
        return None
def unify_var(var,x,subs):
    if var in subs:
        return unify(subs[var],x,subs)
    elif x in subs:
        return unify(var,subs[x],subs)
    else:
        subs2=subs.copy()
        subs2[var]=x
        return subs2
print("unification:",unify(('P','x'),('P','y')))
