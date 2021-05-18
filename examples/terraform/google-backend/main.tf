locals {
  name = "value"
}

output "name" {
  value       = local.name
  description = "example basic terraform"
}

