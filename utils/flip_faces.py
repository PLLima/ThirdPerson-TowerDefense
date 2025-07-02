# FONTE: Gemini
def flip_obj_faces(input_obj_path, output_obj_path):
    with open(input_obj_path, 'r') as f_in:
        lines = f_in.readlines()

    flipped_lines = []
    for line in lines:
        if line.startswith('f '):
            parts = line.split()
            # Extract face components (v/vt/vn or just v)
            face_components = parts[1:]
            # Reverse the order of components
            flipped_components = face_components[::-1]
            flipped_line = 'f ' + ' '.join(flipped_components) + '\n'
            flipped_lines.append(flipped_line)
        else:
            flipped_lines.append(line)

    with open(output_obj_path, 'w') as f_out:
        f_out.writelines(flipped_lines)

# Usage:
flip_obj_faces('./assets/enemies/ballon_heart.obj', './assets/enemies/ballon_heart.obj')