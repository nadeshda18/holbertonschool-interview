#!/usr/bin/python3
"""
Given a list of non-negative integers
representing the height of walls,
compute how much water will be retained after it rains.
"""


def rain(walls):
    """
    walls: list of non-negative integers
    Return: the amount of water retained
    if list is empty return 0
    """
    if not walls or len(walls) < 3:
        return 0

    left_max = [0] * len(walls)
    right_max = [0] * len(walls)

    left_max[0] = walls[0]
    for i in range(1, len(walls)):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[-1] = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    water_retained = 0
    for i in range(len(walls)):
        water_retained += min(left_max[i], right_max[i]) - walls[i]

    return water_retained
