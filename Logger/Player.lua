players = {}
players[0] = { Title = "Video Game Developer", Name = "Emre", Family = "Kovanci", Level = 25 }
players[1] = { Title = "Cyber", Name = "Dilara", Family = "Bozkurt", Level = 24 }

-- 
function AddStuff(a, b)
	print("[LUA] AddStuff("..a..", "..b..") called \n")
	return a + b
end

function GetPlayer(n)
	return players[n]
end