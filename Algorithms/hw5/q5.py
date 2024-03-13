def maximize_antenna_activation(antennas):
    # Sort antennas based on their coverage endpoint in ascending order
    sorted_antennas = sorted(antennas, key=lambda antenna: antenna[1])
    
    # Initialize an empty set to keep track of activated antennas
    activated_antennas = set()
    
    # Iterate through the sorted antennas and activate non-intersecting antennas
    for antenna in sorted_antennas:
        if not any(antenna[0] <= activated_antenna[1] for activated_antenna in activated_antennas):
            # The antenna does not intersect with any activated antennas
            activated_antennas.add(antenna)
    
    return activated_antennas


