.PHONY: clean All

All:
	@echo "----------Building project:[ ArvoreBinaria - Debug ]----------"
	@cd "ArvoreBinaria" && $(MAKE) -f  "ArvoreBinaria.mk"
clean:
	@echo "----------Cleaning project:[ ArvoreBinaria - Debug ]----------"
	@cd "ArvoreBinaria" && $(MAKE) -f  "ArvoreBinaria.mk" clean
