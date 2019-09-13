def vol_tet(u,v,w,U,V,W):
	X = (w-U+v)*(U+v+w)
	x = (U-v+w)*(v-w+U)
	Y = (u-V+w)*(V+w+u)
	y = (V-w+u)*(w-u+V)
	Z = (v-W+u)*(W+u+v)
	z = (W-u+v)*(u-v+W) 
	a = (x*Y*Z)**0.5
	b = (y*Z*X)**0.5
	c = (z*X*Y)**0.5
	d = (x*y*z)**0.5

	return((((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))**0.5)/(192*u*v*w))




def heron(a,b,c):
	s = (a+b+c)/2
	return (s*(s-a)*(s-b)*(s-c))**0.5	

def inradius_tet(vol,a1,a2,a3,a4):
	return 3*vol/(a1+a2+a3+a4)


t = int(input())

for i in range(t):
	w,v,u,U,V,W = map(int,input().split())

	vol = vol_tet(u,v,w,U,V,W)
	a1 = heron(U,V,W)
	a2 = heron(U,v,w)
	a3 = heron(v,u,W)
	a4 = heron(w,u,V)

	print("{:.4f}".format(inradius_tet(vol,a1,a2,a3,a4)))

