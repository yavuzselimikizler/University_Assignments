import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def closest_pair(points):
    # Sort points based on x-coordinates
    points.sort(key=lambda p: p.x)
    return closest_pair_recursive(points)

def closest_pair_recursive(points):
    n = len(points)

    # Base case: if there are 3 or fewer points, use brute force
    if n <= 3:
        return brute_force(points)

    # Divide the points into left and right halves
    mid = n // 2
    left_half = points[:mid]
    right_half = points[mid:]

    # Recursively find the closest pairs in each half
    left_closest = closest_pair_recursive(left_half)
    right_closest = closest_pair_recursive(right_half)

    # Find the minimum distance between pairs from left and right halves
    min_distance = min(left_closest, right_closest)

    # Find points within the strip and sort them by y-coordinate
    strip = points_within_strip(points, mid, min_distance)

    # Check for the closest pairs within the strip
    return min(min_distance, closest_in_strip(strip, min_distance))

def brute_force(points):
    # Brute force method for finding closest pair when there are 3 or fewer points
    min_distance = float('inf')
    n = len(points)

    for i in range(n):
        for j in range(i+1, n):
            distance = calculate_distance(points[i], points[j])
            min_distance = min(min_distance, distance)

    return min_distance

def points_within_strip(points, mid, min_distance):
    mid_point = points[mid]
    # Select points within the strip based on x-coordinates
    strip = [point for point in points if abs(point.x - mid_point.x) < min_distance]
    # Sort points within the strip by y-coordinate
    strip.sort(key=lambda p: p.y)
    return strip

def closest_in_strip(strip, min_distance):
    n = len(strip)

    # Check for the closest pairs within the strip
    for i in range(n):
        for j in range(i+1, min(i+7, n)):
            distance = calculate_distance(strip[i], strip[j])
            min_distance = min(min_distance, distance)

    return min_distance

def calculate_distance(point1, point2):
    # Calculate Euclidean distance between two points
    return math.sqrt((point1.x - point2.x)**2 + (point1.y - point2.y)**2)


