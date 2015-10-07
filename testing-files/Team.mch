MACHINE 
    Team
VARIABLES 
    team
INVARIANT
    team <: 1..22 & 
    card(team) = 11
INITIALISATION
    team := 1..11
OPERATIONS
    substitute(pp, rr) = 
    PRE
        pp : 1..22 & pp : team & 
        rr : 1..22 & rr /: team
    THEN
        team := (team \/ {rr}) - {pp}
    END
END