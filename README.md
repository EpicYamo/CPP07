# CPP Module 07

C++ templates: generic functions, a function applied over any array, and a bounds-checked array class template.

> Part of the **42 school curriculum**. Built by **Arda Aycan**.

## Exercises

| Exercise | Binary | What it demonstrates |
| --- | --- | --- |
| `ex00` | `whatever` | `swap`, `min` and `max` as function templates in the global namespace; `min` and `max` return the second argument when both values are equal. |
| `ex01` | `iter` | `iter` applies a function to every element of an array of any type, accepting both `const T &` and `T &` functions and instantiated function templates such as `print<int>`. |
| `ex02` | `ft_array` | `Array<T>` allocates its elements with `new[]`, deep-copies on copy and assignment, and throws an exception when `operator[]` receives an out-of-bounds index. |

## Build and run

Every exercise has its own Makefile and produces its own binary:

```bash
make -C ex02
./ex02/ft_array
```

`make fclean -C <exercise>` removes the binary again.

## Notes

- C++98, `-Wall -Wextra -Werror`.
- Templates are defined in headers; `ex02` keeps the class declaration in `Array.hpp` and the member definitions in `Array.tpp`.
- In `ex01`, the element type and the function type are separate template parameters, so const arrays only accept functions that do not modify their elements.
- `ex02` value-initializes its elements (`new T[n]()`), so an `Array<int>` starts filled with zeros.

## Author

**Arda Aycan** ([@EpicYamo](https://github.com/EpicYamo)).
