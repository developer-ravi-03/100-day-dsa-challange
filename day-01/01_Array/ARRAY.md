# Array

- In c++ passing of array are of 4 types

1. As a sized array
2. As an unsized array
3. As a pointer (pass by pointer)
4. As a reference (pass by reference)

## 🔹 What’s the difference?

### Feature

- Pass by Value | Pass by Reference
- Copy of array made? ✅ Yes (if possible, but not directly for raw arrays) | ❌ No (works with the actual array)
- Changes affect original? ❌ No |✅ Yes
- Usage with arrays ❌ Not typically used (C++ doesn’t allow full array copy in function arguments) | ✅ Yes

# 🔸 1. Pass by Pointer (int \*arr)

```bash
void func(int *arr) { ... }
```

#### This is the most common and flexible method.

### ✅ Characteristics:

- Actually passes the address of the first element.

- Allows you to use arr[i] or pointer arithmetic (\*(arr + i)).

- You can’t get the size of the array inside the function (sizeof(arr) gives size of pointer).

- Works for arrays of any size.

# 🔸 2. Pass by Reference to Array (int (&arr)[N])

```bash
void func(int (&arr)[5]) { ... }

```

### ✅ Characteristics:

- Passes a reference to the whole array.

- You can still use arr[i].

- The compiler knows the size of the array inside the function (sizeof(arr) works).

- You must specify the size of the array ([5] or template).

- More type-safe (no accidental pointer decays).
