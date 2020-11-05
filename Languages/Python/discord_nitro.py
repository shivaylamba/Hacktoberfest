import discord
import random
import os
import datetime
from discord.ext import commands

with open('helpcommand.txt', 'r') as f:
    f_contents = f.read()
message = (f_contents)
def gen():
    chars = ['a', 'b', 'c', 'd',  'e','f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
    '1','2','3','4','5','6','7','8','9','0'
    ]
    return "".join(random.choices(chars, k=16))
Client = discord.Client()
link = "https://discord.gift/"

@Client.event
async def on_ready():
    song_name='for user commands' 
    activity_type=discord.ActivityType.listening
    await Client.change_presence(activity=discord.Activity(type=activity_type,name=song_name))
    print(Client.user.name)

@Client.event
async def on_message(message):
    x=0
    if message.author == Client.user:   
        return
    if message.content == '/nitro':
        logmess = "Command run at:"+str(datetime.datetime.now())+"\n"
        f=open("log.txt", "a+")
        f.write(logmess)
        game=discord.Game(name="""Generating Nitro Codes""")
        await Client.change_presence(activity=game)
        while x < 50:
            await message.channel.send(link + gen())
            x=x+1
        else:
            return

#client = MyClient()
Client.run(os.environ['TOKEN'])
