public class Main {
	static boolean old_tofix() {
		int	count = 0;
		while (count < total) {
			count++; // not a compile time error but meaning error
			if (this.getName(count) == nametable.userName()) { 
				return (true);
			}
		}
	}

	static boolean new_is_namesync() {
		int count = 0;
		while (count < total) {
			if (this.getName(count) != nametable.userName(count)) {
				return (false);
			}
			count++;
		}
		return (true);
	}
}
