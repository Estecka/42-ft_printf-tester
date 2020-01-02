# 42-ft_printf-tester
Personal makeshift tester for 42's ft_printf project


## Requirements
This tester works using **vprintf** rather than **printf**, so it requires that you declare an equivalent into your header and sources :  
```
int ft_vprintf(const char*, va_list);
```

The implementation of ft_vprintf is typically almost identical to ft_printf, the only differences being the va_list declared in the parameter list rather than the function's body, and `va_start` never being called.

Though not required by this tester, the matching implementation of `ft_printf` would be :
```
int ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}
```

## Usage
Write an implementation of ft_vprintf if not already done.
Clone into your libft project, and run `make autorun`.
