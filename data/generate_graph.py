import random
import json

# Parameters for the graph.
num_vertices = 3000
edges_per_vertex = 8  # Adjust to guarantee at least 300,000 total edges.
min_weight = -100
max_weight = 100

graph = {}

for i in range(num_vertices):
    vertex = str(i)
    edges = []
    # Generate a fixed number of edges per vertex.
    for _ in range(edges_per_vertex):
        # Choose a random destination vertex that is different from the current vertex.
        dest = random.randint(0, num_vertices - 1)
        while dest == i:
            dest = random.randint(0, num_vertices - 1)
        # Generate a random weight for the edge.
        weight = random.randint(min_weight, max_weight)
        edges.append([dest, weight])
    graph[vertex] = edges

# Write the resulting graph dictionary to a JSON file.
with open("graph.json", "w") as f:
    json.dump(graph, f)

print("JSON graph file with {} vertices and {} edges created.".format(
    num_vertices, num_vertices * edges_per_vertex))
