def search(name):
	search_queue  =deque()
	search_queue +=graph[name]
	searched = []
	while search_queue:
		person = search_queue.popleft()
		if not person in searched:
			if person_is_seller(person):
				return True
			else:
				search_queue +=graph[person]
				search.append(person)
	return False
search("you")