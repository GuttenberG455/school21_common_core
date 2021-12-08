SRCS_PUSH_SWAP	= srcs/push_swap/ 
SRCS_CHECKER	= srcs/checker/

PUSH_SWAP		= srcs/push_swap/push_swap
CHECKER_SWAP	= srcs/checker/checker

RM			= rm -f


all:	push_swap checker
push_swap:	
			$(MAKE) -C $(SRCS_PUSH_SWAP)
			cp $(PUSH_SWAP) .

checker:
			$(MAKE) -C $(SRCS_CHECKER)
			cp $(CHECKER_SWAP) .


clean_checker: 
			$(MAKE) clean -C $(SRCS_CHECKER)

clean_push_swap: 
			$(MAKE) clean -C $(SRCS_PUSH_SWAP)

clean:		clean_checker clean_push_swap

fclean_push_swap:
			$(MAKE) fclean -C $(SRCS_PUSH_SWAP)
			$(RM) push_swap

fclean_checker:
			$(MAKE) fclean -C $(SRCS_CHECKER)
			$(RM) checker

fclean:	fclean_checker fclean_push_swap

re:		fclean all

.PHONY: all clean fclean re