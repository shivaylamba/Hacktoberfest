data = read.csv(file = "Play.csv")

##########FIND COUNT##########
PlayData = data$Play
cntNo = 0
cntYes = 0

for(val in PlayData)
{
  if(val == "No")
  {
    cntNo = cntNo + 1
  }
  if(val == "Yes")
  {
    cntYes = cntYes + 1
  }
}

print(cntNo)
print(cntYes)

#OutlookData calculate Count for Play and NoPlay

OutlookData = data$Outlook
print(OutlookData)

CntOutlookSunnyPlay = 0
CntOutlookSunnyNoPlay = 0
CntOutlookOvercastPlay = 0
CntOutlookOvercastNoPlay = 0
CntOutlookRainyPlay = 0
CntOutlookRainyNoPlay = 0

for(i in 1 : length(PlayData))
{
  if(OutlookData[i] == "Sunny")
  {
    if(PlayData[i] == "Yes")
      CntOutlookSunnyPlay = CntOutlookSunnyPlay + 1
    if(PlayData[i] == "No")
      CntOutlookSunnyNoPlay = CntOutlookSunnyNoPlay + 1
  }
  if(OutlookData[i] == "Overcast")
  {
    if(PlayData[i] == "Yes")
      CntOutlookOvercastPlay = CntOutlookOvercastPlay + 1
    if(PlayData[i] == "No")
      CntOutlookOvercastNoPlay = CntOutlookOvercastNoPlay + 1
  }
  if(OutlookData[i] == "Rainy")
  {
    if(PlayData[i] == "Yes")
      CntOutlookRainyPlay = CntOutlookRainyPlay + 1
    if(PlayData[i] == "No")
      CntOutlookRainyNoPlay = CntOutlookRainyNoPlay + 1
  }
}

print(CntOutlookSunnyPlay)
print(CntOutlookSunnyNoPlay)   
print(CntOutlookOvercastPlay)     
print(CntOutlookOvercastNoPlay)       
print(CntOutlookRainyPlay)       
print(CntOutlookRainyNoPlay)   

#TemperatureData calculate Count for Play and NoPlay

TempData = data$Temp
print(TempData)

CntTempHotPlay = 0
CntTempHotNoPlay = 0
CntTempCoolPlay = 0
CntTempCoolNoPlay = 0
CntTempMildPlay = 0
CntTempMildNoPlay = 0
for(i in 1 : length(PlayData))
{
  if(TempData[i] == "Hot")
  {
    if(PlayData[i] == "Yes")
      CntTempHotPlay = CntTempHotPlay + 1
    if(PlayData[i] == "No")
      CntTempHotNoPlay = CntTempHotNoPlay + 1
  }
  if(TempData[i] == "Cool")
  {
    if(PlayData[i] == "Yes")
      CntTempCoolPlay = CntTempCoolPlay + 1
    if(PlayData[i] == "No")
      CntTempCoolNoPlay = CntTempCoolNoPlay + 1
  }
  if(TempData[i] == "Mild")
  {
    if(PlayData[i] == "Yes")
      CntTempMildPlay = CntTempMildPlay + 1
    if(PlayData[i] == "No")
      CntTempMildNoPlay = CntTempMildNoPlay + 1
  }
}

print(CntTempHotPlay)
print(CntTempHotNoPlay)   
print(CntTempCoolPlay)     
print(CntTempCoolNoPlay)       
print(CntTempMildPlay)       
print(CntTempMildNoPlay)   

#HumidityData calculate Count for Play and NoPlay

HumidityData = data$Humidity
print(HumidityData)

CntHumidityHighPlay = 0
CntHumidityHighNoPlay = 0
CntHumidityNormalPlay = 0
CntHumidityNormalNoPlay = 0

for(i in 1 : length(PlayData))
{
  if(HumidityData[i] == "High")
  {
    if(PlayData[i] == "Yes")
      CntHumidityHighPlay = CntHumidityHighPlay + 1
    if(PlayData[i] == "No")
      CntHumidityHighNoPlay = CntHumidityHighNoPlay + 1
  }
  if(HumidityData[i] == "Normal")
  {
    if(PlayData[i] == "Yes")
      CntHumidityNormalPlay = CntHumidityNormalPlay + 1
    if(PlayData[i] == "No")
      CntHumidityNormalNoPlay = CntHumidityNormalNoPlay + 1
  }
}

print(CntHumidityHighPlay)
print(CntHumidityHighNoPlay)   
print(CntHumidityNormalPlay)     
print(CntHumidityNormalNoPlay)       

#WindyData calculate Count for Play and NoPlay

WindyData = data$Windy
print(WindyData)

CntWindyTPlay = 0
CntWindyTNoPlay = 0
CntWindyFPlay = 0
CntWindyFNoPlay = 0

for(i in 1 : length(PlayData))
{
  if(WindyData[i] == "TRUE")
  {
    if(PlayData[i] == "Yes")
      CntWindyTPlay = CntWindyTPlay + 1
    if(PlayData[i] == "No")
      CntWindyTNoPlay = CntWindyTNoPlay + 1
  }
  if(WindyData[i] == "FALSE")
  {
    if(PlayData[i] == "Yes")
      CntWindyFPlay = CntWindyFPlay + 1
    if(PlayData[i] == "No")
      CntWindyFNoPlay = CntWindyFNoPlay + 1
  }
}

print(CntWindyTPlay)
print(CntWindyTNoPlay)   
print(CntWindyFPlay)     
print(CntWindyFNoPlay)       

#################### Find Play or No Play ##################

findPlayNoPlay <- function(Outlook,Temp,Humidity,Windy)
{
    if(Outlook == "Sunny")
    {
      O1 = CntOutlookSunnyPlay 
      O2 = CntOutlookSunnyNoPlay
    }
    if(Outlook == "Overcast")
    {
      O1 = CntOutlookOvercastPlay 
      O2 = CntOutlookOvercastNoPlay
    }
    if(Outlook == "Rainy")
    {
      O1 = CntOutlookRainyPlay 
      O2 = CntOutlookRainyNoPlay
   }
    if(Temp == "Hot")
    {
      T1 = CntTempHotPlay 
      T2 = CntTempHotNoPlay
    }
    if(Temp == "Cool")
    {
      T1 = CntTempCoolPlay 
      T2 = CntTempCoolNoPlay
    }
    if(Temp == "Mild")
    {
      T1 = CntTempMildPlay 
      T2 = CntTempMildNoPlay
    }
    if(Humidity == "High")
    {
      H1 = CntHumidityHighPlay
      H2 = CntHumidityHighNoPlay
    }
    if(Humidity == "Normal")
    {
      H1 = CntHumidityNormalPlay
      H2 = CntHumidityNormalNoPlay
    }
    if(Windy == "FALSE")
    {
      W1 = CntWindyFPlay
      W2 = CntWindyFNoPlay
    }
    if(Windy == "TRUE")
    {
      W1 = CntWindyTPlay
      W2 = CntWindyTNoPlay
    }
  
    isPlay = (O1 * T1 * H1 * W1) / ((cntYes^3) * 14)
    isNoPlay = (O2 * T2 * H2 * W2) / ((cntNo^3) * 14)
    print(isPlay)
    print(isNoPlay)
    if(isPlay > isNoPlay)
      print("Play")
    else
      print("NoPlay")
}

findPlayNoPlay("Rainy", "Mild", "High", "FALSE")
