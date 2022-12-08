players = {}
players[0] = { Title = "Video Game Developer", Name = "Emre", Family = "Kovanci", Level = 25 }
players[1] = { Title = "Ninja", Name = "Kitty", Family = "Kovanci", Level = 3 }

-- 
function AddStuff(a, b)
	print("[LUA] AddStuff("..a..", "..b..") called \n")
	return a + b
end

function GetPlayer(n)
	return players[n]
end
