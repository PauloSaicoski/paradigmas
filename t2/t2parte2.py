#!/usr/bin/env python3
import itertools

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''

def svgRect(rs):
   (((x,y),w,h),style) = rs
   return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x,y,w,h,style)

def svgImage(w, h, rs):
   return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w,h) + \
          ''.join(map(svgRect, rs)) + "</svg>"

def applyStyles(rects, styles):
   return list(zip(rects, itertools.cycle(styles)))

def genRects(n, w, h):
   return [((x*w,0.0),w,h) for x in range(n)]

def writeFile(fname, contents):
   f = open(fname, 'w')
   f.write(contents)
   f.close()

def genStyles(n, q):
    y = (140/2)/(q-1) #a variavel "q" define a quantia de blocos antes das cores espelharem
    return ["fill:rgb(%d,%d,0)" %(x*y,140-x*y) if x%2 == 0 else "fill:rgb(%d,%d,0)" %(140-(x-1)*y,(x-1)*y)for x in range(n)]

def main():
   maxWidth = 1000
   maxHeight = 100
   rects = genRects(10,50,50)
   styles = genStyles(10, 5)
   rectstyles = applyStyles(rects, styles)
   writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))
   

if __name__ == '__main__':
   main()
   
