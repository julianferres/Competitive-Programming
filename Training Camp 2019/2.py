class Fraccion(object):
    """docstring for Fraccion."""

    def __init__(self, p,q):
        self.num = p
        self.den = q

    def __lt__(self, other):
        return self.num*other.den > self.den*other.num

    def __gt__(self, other):
        return self.num*other.den > self.den*other.num

    def __eq__(self, other):
        return self.num*other.den == self.den*other.num
