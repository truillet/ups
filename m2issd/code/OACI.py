#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Exercice 2 - prononciation ICAO
#
import os 

# definir le dictionnaire
ICAO = {'a':'alpha', 'b':'bravo', 'c':'charlie', 'd':'delta', 'e':'echo', 'f':'foxtrot','g':'golf','h':'hotel', 'i':'india', 'j':'juliett', 'k':'kilo','l':'lima','m':'mike','n':'november','o':'oscar','p': 'papa','q':'quebec','r':'romeo', 's':'sierra', 't':'tango', 'u':'uniform','v':'victor','w':'whiskey','x':'x-ray','y':'yankee','z':'zulu', ' ':'tiret'}

def speak_ICAO(txt):
	txt_code = ''
	# pour chacune des lettes, trouver sa correspondante codee
	for i in range(len(txt)):
		txt_code = txt_code + ICAO[txt[i]] + ' '
	
	# afficher le texte
	# os.system("espeak -ven \"" + txt_code + "\" 2>/dev/null") # UNIX - envoi des messages d'erreur à la poubelle 
	os.system("SayStatic " + txt_code) # Windows
	return(txt_code)

def main():
	txt = raw_input('entrez une chaine a encoder : ')
	speak_ICAO(txt) 

if __name__ == '__main__':
	main()
