with open("stone_story.md", mode='r', encoding='utf-8') as in_file, \
        open("stone_story_2.md", mode='w', encoding='utf-8') as out_file:
    content = in_file.read().replace("/u", '/span').replace("u",
                                                            'span style="text-decoration: underline;"')
    out_file.write(content)
