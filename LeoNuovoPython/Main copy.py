from Talker import Talker

#change <api> with your api
#Custom elevenlabs voice (if you haven't installed it, it's not going to work)
el1 = Talker("MhCxqsUNqPcgb5bNYy5r", "<api>", False)
#Standard elevenlabs
el2 = Talker("21m00Tcm4TlvDq8ikWAM", "<api>", False)
#gTTS
en = Talker("en", "", False)
it = Talker("it", "", False)
ja = Talker("ja", "", False)
cn = Talker("zh-TW", "", False)

#Here some examples.

#Elevenlabs (works because is in the database)
el1.talk("This is Elevenlabs, Hello Ladies and gentlemen, distinguished guests, and fellow TTS enthusiasts")

el1.talk("Talker è una libreria di sintesi vocale (TTS) che converte il testo in audio parlato. Supporta diverse voci e motori TTS (usa Elevenlabs, gTTS e pyttsx3). Creata da Thomas Causetti")

el2.talk("This library works well with different languages")

el2.talk("こんにちは TTS")

#gTTS
en.talk("This is gTTS, Hello Ladies and gentlemen, distinguished guests, and fellow TTS enthusiasts")

it.talk("Buongiorno signore e signori, illustri ospiti e amici appassionati di TTS")

ja.talk("こんにちは TTS")

cn.talk("你好 TTS")

#japanglish
ja.talk("Hello Ladies and gentlemen, distinguished guests, and fellow TTS enthusiasts")

#failsafe
f = Talker("error", "error", False)
f.talk("Failsafe, works also offline")

# Elevenlabs example
# is commented because it needs an API key and a voice id
# ele = Talker("VOICEID", "API", False)
# ele.talk("Ciao")
"""

Some Elevenlabs voices id

Rachel; 21m00Tcm4TlvDq8ikWAM
Drew; 29vD33N1CtxCmqQRPOHJ
Clyde; 2EiwWnXFnvU5JabPnv8n
Paul; 5Q0t7uMcjvnagumLfvZi
Domi; AZnzlk1XvdvUeBnXmlld
Dave; CYw3kZ02Hs0563khs1Fj
Fin; D38z5RcWu1voky8WS1ja
Sarah; EXAVITQu4vr4xnSDxMaL
Antoni; ErXwobaYiN019PkySvjV
Thomas; GBv7mTt0atIp3Br8iCZE
Charlie; IKne3meq5aSn9XLyUdCD
George; JBFqnCBsd6RMkjVDRZzb
Emily; LcfcDJNUP1GQjkzn1xUU
Elli; MF3mGyEYCl7XYWbV9V6O
Callum; N2lVS1w4EtoT3dr4eOWO
Patrick; ODq5zmih8GrVes37Dizd
Harry; SOYHLrjzK2X1ezoPC6cr
Liam; TX3LPaxmHKxFdv7VOQHJ
Dorothy; ThT5KcBeYPX3keUQqHPh
Josh; TxGEqnHWrfWFTfGW9XjX
Arnold; VR6AewLTigWG4xSOukaG
Charlotte; XB0fDUnXU5powFXDhCwa
Alice; Xb7hH8MSUJpSbSDYk0k2
Matilda; XrExE9yKIg1WjnnlVkGX
Matthew; Yko7PKHZNXotIFUBG7I9
James; ZQe5CZNOzWyzPSCn5a3c
Joseph; Zlb1dXrM653N07WRdFW3
Jeremy; bVMeCyTHy58xNoL34h3p
Michael; flq6f7yk4E4fJM5XTYuZ
Ethan; g5CIjZEefAph4nQFvHAz
Chris; iP95p4xoKVk53GoZ742B
Gigi; jBpfuIE2acCO8z3wKNLl
Freya; jsCqWAovK2LkecY7zXl4
Brian; nPczCjzI2devNBz1zQrb
Grace; oWAxZDx7w5VEj9dCyTzz
Daniel; onwK4e9ZLuTAKqWW03F9
Lily; pFZP5JQG7iQjIQuC4Bku
Serena; pMsXgVXv3BLzUgSXRplE
Adam; pNInz6obpgDQGcFmaJgB
Nicole; piTKgcLEGmPE4e6mEKli
Bill; pqHfZKP75CvOlQylNhV4
Jessie; t0jbNlBVZ17f02VDIeMI
Sam; yoZ06aMxZJJ28mfd3POQ
Glinda; z9fAnlkpzviPz146aGWa
Giovanni; zcAOhNBS3c14rBihAFp1
Mimi; zrHiDhphv9ZnVXBqCLjz

if on your system are different try with:
https://help.elevenlabs.io/hc/en-us/articles/14599760033937-How-do-I-find-my-voices-ID-of-my-voices-via-the-website-and-through-the-API
"""
