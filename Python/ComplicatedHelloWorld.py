def E():
  e = 'abbreviation'
  e = e[4]
  return(e)
def H():
  h = 'checkmate'
  h = h[1]
  return(h)
def L():
  l = 'mycelium'
  l = l[4]
  return(l)
def W():
  w = 'kachow'
  w = w[5]
  return(w)
def O():
  o = 'cardboard'
  o = o[5]
  return(o)
def R():
  r = 'lightsaber'
  r = r[9]
  return(r)
def D():
  d = 'dinosaur'
  d = d[0]
  return(d)
def space():
  space = 'book report'
  space = space[4]
  return(space)
def exclamatoryMarking():
  xMark = 'Nooooooooooooooooooo!'
  xMark = xMark[20]
  return(xMark)
completeEarthlyGreeting = H().upper() + E() + L() + L() + O() + space() + W().upper() + O() + R() + L() + D() + exclamatoryMarking()
print(completeEarthlyGreeting)
