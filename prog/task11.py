facts={"bird(tweety)","cat(sylvester)","fish(nemo)"}
rules={"bird(x)->canfly(x)"}
def infer(facts,rules):
    derived=set()
    for r in rules:
        lhs,rhs=r.split("->")
        lhs=lhs.strip()
        rhs=rhs.strip()
        pred,arg=lhs[:-1].split("(")
        for f in facts:
            if f.startswith(pred):
                derived.add(rhs.replace("x", f[f.index("(") + 1: -1]))
    return derived
print("facts:",facts)
print("inferred:",infer(facts,rules))
