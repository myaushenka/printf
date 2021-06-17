
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_string(t_list *tab)
{
	char	*s;
	int		i;
	int		len;
	int		p;

	i = 0;
	p = tab->prec;
	s = va_arg(tab->args, char *);
	len = ft_strlen(s);
	if ((tab->width > tab->prec || tab->width > len) && !tab->dash)
		ft_align_char(tab, len);
	while (s[i] && p--)
		tab->length += write(1, &s[i++], 1);
	if (tab->width > len && tab->dash)
		ft_complete_char(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_char(t_list *tab)
{
	char	c;
	int		len;

	len = 1;
	c = va_arg(tab->args, int);
	if ((tab->width > tab->prec || tab->width > len) && !tab->dash)
		ft_align_char(tab, len);
	tab->length += write(1, &c, 1);
	if (tab->width > len && tab->dash)
		ft_complete_char(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_percent(t_list *tab)
{
	int	len;

	len = 1;
	if ((tab->width > tab->prec || tab->width > len) && !tab->dash)
		ft_align_char(tab, len);
	tab->length += write(1, "%", 1);
	if (tab->width > len && tab->dash)
		ft_complete_char(tab, len);
	tab = ft_clean_flags(tab);
}